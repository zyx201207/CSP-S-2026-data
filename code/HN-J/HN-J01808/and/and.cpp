#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[n+1];
	int cou[m+1];
	int k=1;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	
	sort(s+1,s+n+1,cmp);
	
	if(m==1){
		cout<<s[1];
		return 0;
	}
	if(m==2){
		int max=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(s[i]&s[j]>max){
					cout<<s[i]<<" "<<s[j]<<endl;
					max=s[i]&s[j];
				} 
			}
		}
		cout<<max;
		return 0;
	}
	if(m==n){
		int a[n+1];
		a[1]=s[1];
		for(int i=2;i<=m;i++){
			a[i]=s[i]&a[i-1];
		}
		cout<<a[m];
		return 0;
	}
	if(m==n-1){
		int a[n+1];
		int max=0;
		for(int i=1;i<=n;i++){
			int a2[n+1];
			for(int j=1;j<=n;j++){
				if(j!=i) a2[j]=i;
			}
			a[1]=a2[1];
			for(int i=2;i<=m;i++){
				a[i]=a2[i]&a[i-1];
			}
			if(a[m]>max) max=a[m];
		}
		
		cout<<max;
		return 0;
	}
	int num=1;
	int a[n+1];
	a[1]=s[1];
	for(int i=2;i<=m;i++){
//		cout<<s[i]<<" ";
		a[i]=s[i]&a[i-1];
	}
//	cout<<"]"<<endl<<num;
	cout<<a[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
