#include<bits/stdc++.h>
#define in long long
using namespace std;
struct fu{
	in num;
	char b;
}k[1000001];
struct fin{
	in group,ij,sum;
	string st;
};
fin lef,rig;
in n,lon=0,sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	in p=0;
	for(int i=1;i<=n;i++){
		cin>>k[i].num>>k[i].b;
		lon+=k[i].num;
	}
	lef.group=1,lef.ij=1,lef.st=k[1].b,lef.sum=1;
	rig.group=n,rig.ij=k[n].num,rig.st=k[n].b,lef.sum=1;
	while(lef.sum+rig.sum+p<lon){
		if(lef.group==rig.group&&lef.ij==rig.ij||(lef.group+1==rig.group&&lef.ij==k[lef.group].num&&rig.ij==1)){
			if(lef.st!=rig.st){
				sum++;
				p++;
				break;
			}else{
				p++;
				break;
			}
		}
		if(lef.ij>k[lef.group].num){
			lef.group+=1,lef.ij=1;
		}if(rig.ij<1){
			rig.group-=1,rig.ij=k[rig.group].num;
		}
		lef.sum++,rig.sum++;lef.ij++,rig.ij--;
		if(lef.st!=rig.st){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
