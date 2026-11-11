#include<bits/stdc++.h>
#define fre(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define logn long
#define itn int
using namespace std;
long long n,m,a[200005],max_len=0,sum_len=0,maxx_ans=0,lost;
bool f[200005];
string h,s[200005];
int main(){
	fre("and");
	cin>>n>>m;
	lost=n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		long long a2=a[i];
		while(a2){
			s[i]=(char)(a2%2+'0')+s[i];
			a2/=2;
		}
		max_len=max(max_len,(long long)s[i].size());
	}
	for(itn i=0;i<n;i++){
		s[i]=string(max_len-s[i].size(),'0')+s[i];
	}
	sum_len=max_len;
	bool op=1;
	h=string(max_len,'0');
	for(int i=0;i<max_len;i++){
		long long ans=0;
		for(int j=0;j<n;j++){
			if(s[j].size()>=sum_len){
				if(s[j][i]=='1' and f[j]==0){
					ans++;
//					cout<<i<<" "<<s[j]<<" "<<a[j]<<endl;
				}
				else if(lost>m and !op)f[j]=1,lost--;
			}
		}
		if(ans>=m){
			h[i]='1';
			op=0;
		}
		else if(op)sum_len--;
//		cout<<h<<endl<<endl;
	}
	long long up=0;
	for(int i=max_len-1;i>=0;i--){
		maxx_ans+=(h[i]-'0')*pow(2,up++);
//		cout<<maxx_ans<<" "<<up<<" "<<(h[i]-'0')*pow(2,up-1)<<endl;
	}
	cout<<maxx_ans;
	return 0;
}
