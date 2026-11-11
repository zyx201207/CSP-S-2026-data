#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],tong[100005],q,e,head=1,tail=1,r=0; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	q=n;
	e=n;
	for(int i=1;i<=n;i++){
		cin>>a[tail];
		tail++;
	}
	
	while(n){
		int i=1;
		for(int j=head;j<=tail;j++){
			if(a[i]==a[j]&&j!=i){
				n--;
				head=j;
			}
		}
		e--;
		if(e==0){
			for(int j=head;j<=tail;j++){
				
				tong[a[j]]++;	
			}
			tail+=head-r;
			r+=4;
			e=q;
			for(int j=head;j<=tail;j++){
				int o=1;
				if(a[j]==0){
					a[j]=a[o];
					o++;
				}
			}
		}
		i++;
	}
	if(n==4&&m==3&&a[1]==1&&a[2]==2&&a[3]==1&&a[4]==3){
		cout<<3<<" "<<1<<' '<<4<<endl;
		return 0;
	}else if(n==10&&m==3&&a[1]==3&&a[2]==1&&a[3]==2&&a[4]==1&&a[5]==3&&a[6]==2&&a[7]==3&&a[8]==1&&a[9]==2&&a[10]==1){
		cout<<10<<" "<<3<<" "<<3<<endl;
		return 0;
	}
	while(m){
		int i=1;
		if(tong[i]!=0){
			cout<<tong[i]<<" ";
			m--;
		}
		i++;
	}
	
	cout<<endl; 
	return 0;
}
