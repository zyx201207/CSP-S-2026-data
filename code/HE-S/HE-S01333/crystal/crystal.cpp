#include<bits/stdc++.h>
using namespace std;
int n,m,neng[500005];
void shuru(){
	int i;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>neng[i];
	}
}
void cwork(){
	int ks,i,smax=0,d;
	for(i=1;i<=n;i++){
		d=neng[i];
		if(m>0){
			if(d!=neng[i+1]){
				d=d+1;
				m=m-1;
			}
			if(d==neng[i+1]){
				smax=smax+1;
				neng[i+1]=neng[i+1]+1;
				m=m-1;
			}	
						
		}
	}
	cout<<smax;
}

/*void cwork(){
	int ks,i,smax=1,d,x;

	
	
	
	
	for(i=1;i<=n;i++){
		d=neng[i];
		if(m>0){
			if(d!=neng[i+1]){
				d=d+1;
				m=m-1;
			}
			if(d==neng[i+1]){
				smax=smax+1;
				if(smax<m){
					m=m-smax;
					
				}
			}	
						
		}
		

		if(m==0){
			for(i=1;i<=n;i++){
				if(neng[i]==neng[i+1]){
					ans=ans+1;
				}
			}
		}
		cout<<ans;
		
		
		
	}
}
*/




int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	shuru();
	if(n==1){
		cout<<1;
	}else{
		cwork();
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
