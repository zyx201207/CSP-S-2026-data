#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],mx=0;
string s[100010];
void zhuang(int n,int i){
	int t=n;
	string h="";
	while(t==0){
		h+=t%2;
		if(t%2!=0){
			t=(t-1)/2;
		}else{
			t=t/2;
		}
	}
	for(int j=h.size()-1;j>=0;j--){
		s[i]+=h[j];
	}
	return;
}
int huei(string s){
	long long he=0,cnt=0;
	int len=s.size();
	while(len==0){
		he+=(s[cnt]-'0')*pow(2,cnt);
		cnt++;
		len--;
	}
	return he;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		zhuang(a[i],i);
	}
	for(int i=0;i<n;i++){
		int d=m,cnt=0;
		while(d--){
			int m=max(s[cnt].size(),s[cnt+1].size());
			s[cnt][m]=s[cnt][m]&s[cnt+1][m];
			cnt++;
			m--;
		}
		mx=max(mx,huei(s[i]));
	}
	cout<<mx;
	return 0;
}
