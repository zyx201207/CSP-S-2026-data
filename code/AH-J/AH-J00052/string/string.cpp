#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
char b[N];
signed main(){
	//rp++
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char last='#';
	int s=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		char c;
		cin>>c;
		if(c!=last)s++,last=c;
		a[s]+=x;
		b[s]=c;
	}
	n=s;
//	for(int i=1;i<=s;i++){
//		cout<<a[i]<<' ';
//	}
//	cout<<s;
	int ans=0;
	int l=1;
	int r=n;
	while(1){
		if(n==1){
			cout<<ans;
			return 0;
		}
		int t=a[l];
		while(t>0){
			if(n==2){
				if(a[l]>a[r]){
					cout<<ans+a[r];
					return 0;
				}	
			}
			//cout<<t<<' ';
			if(b[l]!=b[r]){
				if(t-a[r]<0)ans+=t,a[r]-=t,t=0;
				else ans+=a[r],t-=a[r--],n--;
			}
			else{
				if(t-a[r]<0)a[r]-=t,t=0;
				else{
					t-=a[r--];
					n--;
				}
			}
		}
		n--;
		l++;
	}
	//cout<<ans;
	return 0;
} 
/*
5
1 a
2 c
3 j
4 k
6 j
*/
