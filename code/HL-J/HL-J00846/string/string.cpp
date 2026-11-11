//邦吧卡邦~
//爱丽丝要成为最厉害的OIer！
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n;
int a[N];
char c[N];
int ans;
int cnt;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	char f,t;
	int fn,tn;
	//aaaaabb bbbbbaa
	f=c[1],t=c[n],fn=a[1],tn=a[n];
	for(int i=1,j=n;i<j;){
		//cout<<i<<" "<<j<<endl;
		//cout<<"f:"<<f<<" fn:"<<fn<<"\n"<<"t:"<<t<<" tn:"<<fn<<"\n\n";
		if(f==t){
			if(fn>tn){
				j--;
				fn-=tn;
				tn=a[j];
			}
			else if(fn<tn){
				i++;
				tn-=fn;
				fn=a[i];
			}
			else if(fn==tn){
				j--;
				i++;
				fn=a[i];
				tn=a[j];
			}
		}
		else{
			if(fn>tn){
				ans+=tn;
				j--;
				fn-=tn;
				tn=a[j];
			}
			else if(fn<tn){
				ans+=fn;
				i++;
				tn-=fn;
				fn=a[i];
			}
			else if(fn==tn){
				ans+=fn;
				j--;
				i++;
				fn=a[i];
				tn=a[j];
			}
		}
		
	}
	//cout<<"f:"<<f<<" fn:"<<fn<<"\n"<<"t:"<<t<<" tn:"<<fn<<"\n\n";
	cout<<ans;
	return 0;
}

/*
4
4 a
5 b
3 b
2 a

aaaabbb bbbbbaa
*/