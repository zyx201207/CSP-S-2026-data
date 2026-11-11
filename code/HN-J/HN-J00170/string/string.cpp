#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxx=2e5+10;
int n;
char c[maxx],c1[maxx];
int num[maxx],num1[maxx];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>c[i];
		num1[i]=num[i];
		c1[i]=c[i];
	}
	int i=1,j=n;
	for(;;){
//		cout<<"i:"<<i<<" j:"<<j<<" ans:"<<ans<<" num[i]:"<<num[i]<<" num1[j]:"<<num1[j]<<"\n";
		if(i>n || j<1) break;
		int l=0;
		if(num[i]>num1[j]){
			l=num[i]-num1[j];
			num[i]=l;
			if(c[i]!=c1[j]){
				ans+=num1[j];
			}
			j--;
			
		}
		else if(num1[j]>num[i]){
			l=num1[j]-num[i];
			num1[j]=l;
			if(c[i]!=c1[j]){
				ans+=num[i];
			}
//			cout<<"luby"<<j<<"\n";
			
			i++;
		}else{
			if(c[i]!=c1[j]){
				ans+=num[i];
			}
			num1[j]=0;
			num[i]=0;
			i++;
			j--;
		}
	}
	cout<<ans/2;
	return 0;
}

