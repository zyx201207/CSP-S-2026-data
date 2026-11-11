#include<iostream>
using namespace std;
long long a[109999999];
long long cnt=0;
int main(){
	freopen("card.in","r",stdin);
	 freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
int d[m+1]={0};
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++){
	int b[999999]={0};
	int c[500005]={0};
	for(int j=i;j<n;j++){
		if(b[a[j]]==0){
		c[cnt]=a[j];
		}else{
			for(int s=b[a[j]];s<cnt;s++){
				b[c[s]]=0;
				c[s]=0;
			}
			cnt=b[a[j]];
		}
		cnt++;
		b[a[j]]=cnt;
		
	}
	for(int j=0;j<cnt;j++){
		d[c[j]]+=1;
	}
}
for(int i=1;i<=m;i++){
	cout<<d[i]<<" ";
}
cout<<endl;
	return 0;
}
