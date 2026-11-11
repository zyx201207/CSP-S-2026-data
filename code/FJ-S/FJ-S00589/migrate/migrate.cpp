#include<bits/stdc++.h>
using namespace std;

int c,t;
long long n,d;
long long x[2000005];
long long xy[2000005];
long long sum;
int len[2000005];

void vvv(int a,int b,int c,int len_){
	if(!c){
		len[len_]+=1;
		return ;
	}
	for(int i=a+1;i<=b-c;i++){
		if(xy[i]-xy[a]>d){
			break;
		}
		vvv(i,b,c-1,len_+1);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		cin>>x[1];
		for(int i=2;i<=n;i++){
			cin>>x[i];
			xy[i]=x[i]-xy[i-1];
		}
		for(int i=1;i<n-3;i++){
			for(int j=i+3;j<=n;j++){
				for(int k=1;k<j-i-1;k++){
					vvv(i,j,k,0);
				}
				for(int k=1;k<=n;k++){
					if(len[k]==2){
						sum++;
					}
					len[k]=0;
				}
			}
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
}
