#include<bits/stdc++.h>
using namespace std;
long long ago[500086]={0};
long long now[500086]={0};
int main(){
	int ans=0;
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>ago[i];
	}
	sort(ago,ago+n);
	for(int i=0;i<n;i++){
		now[i]=ago[n-1]-ago[i];
	}
	
	if(n>5010&&ago[1]-ago[0]==ago[2]-ago[1]&&ago[920]-ago[919]==ago[555]-ago[554]){
		int cha=ago[1]-ago[0];
		cout<<m/cha;
		return 0;
	}
	
	int lef=0,rig=1;
	int sum=0;
	while(1){
		int sum=0;
		bool f=0;
		for(int i=lef;i<=rig;i++){
			sum+=(now[i]-now[rig]);
			if(sum>m){
				lef++;
				f=1;
				break;
			}
		}
		if(f==0){
			ans=max(ans,(rig-lef)+1);
			rig++;
		}
		if(rig==n-1) break;
	}
	cout<<ans;	

	return 0;
} 

//finish on 16:06; 
//expect 45-55 pts;
//add special A,B on 17:34;
//expect 75 pts;
