#include<bits/stdc++.h>
using namespace std;
long long a[100000],n,d;
int b[100000];
long long minx[100000]={10000};
void ab(int q,int k){
	for(int f=q+1;f<n;f++){
		if(a[f]<=a[q]+d){
		ab(f,k+1);}
	}
	if(k<minx[q]){
		minx[q]=k;
		b[q]=1;
	}
	else if(k==minx[q])b[q]++;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t){
		t--;
		n=0;d=0;
		cin>>n>>d;
		int ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i];	
			b[i]=0;
			minx[i]=10000;
		}
		for(int i=0;i<n;i++){
			for(int p=1;p<n-i;p++){
				if(a[i+p]<=a[i]+d){
				ab(i+p,1);}
				}
			
			
		}
		for(int j=0;j<n;j++){
				if(b[j]==2)ans++;
			}
		cout<<ans-1<<endl;
	}
	return 0;
}
