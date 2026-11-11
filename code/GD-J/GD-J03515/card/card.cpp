#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[300005]; 
int en[500005];
struct w{
	int data,next,prev;
}b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int head=1,tail=1;
		b[1].data=a[i];
		b[1].prev=1;
		b[1].next=1;
		f[a[i]]=1;
		for(int j=i+1;j<=n;j++){
			if(f[a[j]]==0){
				b[tail+1].data=a[j];
				f[a[j]]=tail+1;
				b[tail].next=tail+1;
				b[tail+1].prev=tail;
				b[tail+1].next=tail+1;
				tail++;
			}
			else {
				if(head!=f[a[j]]){
					//cout<<head<<' '<<b[f[a[j]]].prev<<' '<<tail<<endl;
					b[tail+1].data=a[j];
					b[b[f[a[j]]].prev].next=tail+1;
					b[tail+1].prev=b[f[a[j]]].prev;
					b[tail+1].next=tail+1;
					
					for(int z=f[a[j]];;z=b[z].next){
						f[a[z]]=0;
						if(b[z].next==z)
							break;
					}
					
					f[a[j]]=tail+1;
					tail++;
				}
				else {
					//cout<<head<<' '<<b[f[a[j]]].prev<<' '<<tail<<endl;
					b[tail+1].data=a[j];
					b[tail+1].prev=tail+1;
					b[tail+1].next=tail+1;
					for(int z=head;;z=b[z].next){
						f[a[z]]=0;
						if(b[z].next==z)
							break;
					}
					head=tail+1;
					f[a[j]]=head;
					tail++;
				}
			}
		}
		//
		for(int z=head;;z=b[z].next){
			en[b[z].data]++;
			if(b[z].next==z)
				break;
		}
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
	}
	for(int i=1;i<=m;i++){
		cout<<en[i]<<' ';
	}
	return 0;
}
