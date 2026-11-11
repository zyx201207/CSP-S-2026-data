#include<bits/stdc++.h>
using namespace std;
long long n,a,sum=1,ans=0;
struct se{
	long long l,r;
	char ch;
} ht[200005];
long long x=1,y,j,i=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i1=1;i1<=n;i1++){
		cin>>a;
		char c;
		cin>>c;
		ht[i1].l=sum;
		ht[i1].r=a+sum-1;
		ht[i1].ch=c;
		sum+=a;
	}
	y=sum-1;
	j=n;
	while(x<=y){
		if(ht[i].r>=x && ht[i].l<=x){
			if(ht[j].r>=y && ht[j].l<=y){
				if(ht[i].ch!=ht[j].ch){
					if(ht[i].r-x+1>y-ht[j].l+1){
						ans+=y-ht[j].l+1;
						x+=y-ht[j].l+1;
						y-=y-ht[j].l+1;
						j--;
					}else{
						ans+=ht[i].r-x+1;
						y-=ht[i].r-x+1;
						x+=ht[i].r-x+1;
						i++;
					}
				}
				else{
					if(ht[i].r-x+1>y-ht[j].l+1){
						x+=y-ht[j].l+1;
						y-=y-ht[j].l+1;
						j--;
					}else{
						y-=ht[i].r-x+1;
						x+=ht[i].r-x+1;
						i++;
					}
				}
			}else{
				j--;
			}
		}else{
			i++;
		}
	}
	cout<<ans;
	return 0;
}
