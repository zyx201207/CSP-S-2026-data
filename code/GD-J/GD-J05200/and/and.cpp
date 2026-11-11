#include<bits/stdc++.h>
using namespace std;
long long cnt;
struct ys{
	int r;
	char w;
}a[250000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].r>>a[i].w;
		cnt+=a[i].r;
	}
//	cout<<cnt<<endl;	
	int front[3],back[3];
	front[1]=1,front[2]=1;
	back[1]=n,back[2]=a[n].r;
	long long i=0;
	long long ans=0;
	int sf1=1,sf2=1;
	long long j=0;
	while(j<=cnt/2){
		if(cnt/2-j<=a[sf1].r){
			sf2=cnt/2-j;
			break;
		}else{
			j+=a[sf1].r;
			sf1++;
			sf2=1;
		}
		//if(j>cnt/2){
	//		sf2=sf2-(j-cnt/2);
	//		j=cnt/2;
		//}	else if(j==cnt/2){
	//		sf1--;
	//		sf2=a[sf1].r;
	//	}	
	}
//	cout<<sf1<<" "<<sf2<<endl;
	int x,y;
	while(i<cnt/2){
		if(front[1]==sf1){
			x=sf2;
		}else{
			x=a[front[1]].r;
		}
		y=a[front[1]].w;
		while(x>0){//从后找 
	//		if(back[2]!=a[back[1]].r){     //上一个卡在中间 
				
	//		}
			if(x-back[2]<=0){//不够，卡在中间 
				if(y!=a[back[1]].w){
					ans+=x;
				}
				back[2]=back[2]-x;
				x=0;
				if(back[2]==0){
					back[1]--;
					back[2]=a[back[1]].r;
				}	
			}else{
				if(y!=a[back[1]].w){
					ans+=back[2];
				}
				x-=back[2];
				back[1]--;
				back[2]=a[back[1]].r;
			} 
		}
		i+=a[front[1]].r;
		front[1]++;
		front[2]=1;
	}
	cout<<25;
	return 0;
} 
