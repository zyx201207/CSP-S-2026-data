#include <bits/stdc++.h>
using namespace std;
long long int a[500010]={0};
int b[200010]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m;
	cin>>n>>m;
	int maxv=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>maxv){
			maxv=a[i];
		}
		b[i+100000]++;
	}
	int i=0,j=0;
	while(1){
		if(b[i]){
			for(int k=0;k<b[i];k++){
				a[j]=i;j++;
			}
		}
		i++;
		if(i>=200010){
			break;
		}
	}
	j=n/2;
	long long int l=a[j];
	long long int c=0,t=1;
	int u=0,d=0;
	while(a[j-d-1]==a[j]){
		d++;
		t++;
	}while(a[j+u+1]==a[j]){
		u++;
		t++;
	}
	while(c<m){
		if(j-d>0&&(l-a[j-d-1]<=t*(a[j+u+1])-l)){
			t++;
			c+=l-a[j-d-1];
			d++;
		}
		else if(j+u<n){
			c+=t*(a[j+u+1]-l);
			t++;
			l=a[j+u+1];
			int u1=u;
			u++;
			
		}
		if(t==n){
			break;
		}
		}
	if(t==n+1){
			if(m-c%t!=0) t--;
		}
	if(c>m){
		t--;
	}
	cout<<t;
	return 0;
} 
