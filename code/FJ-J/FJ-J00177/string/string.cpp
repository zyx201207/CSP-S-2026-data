#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m[N],ans;
char t[N]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>m[i];
		cin>>t[i];
		sum+=m[i];
	}
	int mid=sum/2,cnt1=1,cnt2=n,s=0;
	for(int i=1;i<=n;i++){
		if(t[cnt1]!=t[cnt2]){
			int minn=min(m[cnt1],m[cnt2]);
			s+=minn;
			ans+=minn;
			if(s>=mid){
				cout<<ans;
				return 0;
			}
			m[cnt1]-=minn;
			m[cnt2]-=minn;
			if(m[cnt1]==0){
				cnt1++;
			}
			if(m[cnt2]==0){
				cnt2--;
			}
		}
		else{
			int minn=min(m[cnt1],m[cnt2]);
			s+=minn;
			m[cnt1]-=minn;
			m[cnt2]-=minn;
			if(m[cnt1]==0){
				cnt1++;
			}
			if(m[cnt2]==0){
				cnt2--;
			}
		}
	}
	cout<<ans;
	return 0;
}
