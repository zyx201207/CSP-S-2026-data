#include<iostream>
using namespace std;
#define int long long
#define N 200005
int inpt[N];
char chpt[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>inpt[i]>>chpt[i];
	}
	int p1=1,p2=n;
	int ans=0;
	int cnt=0;
	while(p1!=p2 && p1<=n && p2>=1){
		//cout<<ans<<endl;
		cnt++;
		int sum=0;
		while(inpt[p2]>0 && p1!=p2 && p1<=n && p2>=1){
			cnt++;
			//cout<<ans<<endl;
			if(inpt[p2]>=inpt[p1])inpt[p2]-=inpt[p1];
			else{
				inpt[p1]-=inpt[p2];
				if(chpt[p2]!=chpt[p1])sum+=inpt[p2];
				inpt[p2]=0;
				break;
			}
			if(chpt[p2]!=chpt[p1])sum+=inpt[p1];
			inpt[p1]=0;
			p1++;
		}
		ans+=sum;
		p2--;
	}
	cout<<ans;
	return 0;
}

