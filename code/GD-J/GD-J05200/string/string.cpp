#include<bits/stdc++.h>
using namespace std;
long long cnt;
struct ys{
	int r;
	char w;
}a[250000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].r>>a[i].w;
		cnt+=a[i].r;
	}
	
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
		
	}

	int x,y;
	while(i<cnt/2){
		if(front[1]==sf1){
			x=sf2;
		}else{
			x=a[front[1]].r;
		}
		y=a[front[1]].w;
		while(x>0){
			if(x-back[2]<=0){
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
	cout<<ans<<endl;
	return 0;
} 
