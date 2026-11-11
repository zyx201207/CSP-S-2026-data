#include<bits/stdc++.h>
using namespace std;
#define int long long
long long n;
string m;
long long bj[20005];
long long ans;
long long difer=0;
signed main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	long long kkk=0;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		kkk+=a;
		for(int j=1;j<=a;j++){
			m[j]=c;
		}
	}
	long long iwe=0;
	char mk=m[1];
	for(int i=1;i<=kkk;i++){
		if(m[i]==mk){
			iwe++;
		}
	} 
	if(iwe==kkk){
		cout<<'0';
		return 0;
	}
	for(int i=1;i<=kkk-1;i++){
		for(int j=kkk-1;j>=1;j--){
			if(m[i]!=m[j]&&bj[j]==0&&bj[i]==0){
				difer++;
				bj[i]=kkk-i;
				bj[j]=i;
			}
		}
	}
    cout<<difer;
	return 0;
}

