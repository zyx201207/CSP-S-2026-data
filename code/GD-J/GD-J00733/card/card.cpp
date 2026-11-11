#include<bits/stdc++.h>
using namespace std;
long long n,k,o;
long long a[1000000],b[10000],c[10000],d[100005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
	cin>>a[i];
	} for(long long i=1;i<=n;i++){
	for(long long j=1;j<=n;j++){
	b[j]=0;
	d[j]=0;
	}
	o=1;
	 for(long long j=i;j<=n;j++){
	if(d[a[j]]==0){
	b[o]=a[j];
	d[a[j]]=o;
	o++;
    }else{
    	//o=d[a[j]];
    	int x=d[a[j]];
		for(long long s=d[a[j]]+1;s<=o;s++){
			d[b[s]]=0;
		}
		
			o=x+1;
			//cout<<'p'<<x+1<<'q';
	}
	}
	//cout<<endl;
	for(long long s=1;s<o;s++){
		c[b[s]]++;
		//cout<<b[s]<<' ';
	}//cout<<endl;
	
	
	} 
for(long long s=1;s<=k;s++){
		cout<<c[s]<<endl;
	}

}
