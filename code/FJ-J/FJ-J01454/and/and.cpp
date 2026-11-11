#include<bits/stdc++.h>
using namespace std;
struct node{
	int s;
	string x;
}a[200005];
int n,m,maxn=INT_MIN;
string erjz(int x){
	int t=0;
	string a,b;
	while(x!=0){
		a+=x%2+'0';
		x/=2;
	}
	for(int i=a.size()-1;i>=0;i--){
		b+=a[i];
	}
	return b;
}
int sjz(string x){
	int j=0;
	int s=0;
	for(int i=x.size()-1;i>=0;i--){
		int t=1;
		if(x[i]=='0'){
			j++;
			continue;
		}
		for(int k=1;k<=j;k++){
			t*=2;
		}
		s+=t*(x[i]-'0');
		j++;
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==1||m==1){
		cout<<"0";
		return 0;
	}

	for(int i=1;i<=n;i++){
		cin>>a[i].s;
		a[i].x=erjz(a[i].s);
	}
	for(int i=1;i<=n;i++){
		while((a[i].x).size()!=8){
			a[i].x='0'+a[i].x;
		}
	}	
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			string ans;
			for(int k=0;k<8;k++){
				
				if(a[i].x[k]=='1'&&a[j].x[k]=='1'){
					ans+='1';
				}else{
					ans+='0';
				}
			}
			maxn=max(sjz(ans),maxn);
		}
	}
	cout<<maxn;
	return 0;
}
