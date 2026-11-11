#include<bits/stdc++.h>
using namespace std;
int a[200005]={};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=0,m=0,max1=-1,a1=-1,a2=-1;
	bool t[200005]={};
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int h,g;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(max1<(a[i]&a[j])){
				max1=(a[i]&a[j]);

				h=j;
				g=i;
			}

		}
	}
	t[h]=1,t[g]=1;
	int u=0,max2=0;
	for(int e=1;e<m-1;e++){
		while(t[u]!=0){
			u++;
		}
		
		max2=(a[u]&max1);
		for(int i=0;i<n;i++){
			if(t[i]==0){	
				if(max2<(max1&a[i])){	
					max2=(max1&a[i]);
					t[i]=1;
					t[u]=0;
					u=i;
				}
			
			}
		}
		u=0;
		max1=max2;
	}
	cout<<max1;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
