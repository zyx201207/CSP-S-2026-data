#include<bits/stdc++.h>
using namespace std;
int n,m,a[55000],a1[55000];
int min1=10500;
int min(){
	for(int i=1;i<=n;i++){
		if(a[i]<min1){
			min1=i;
		}
	} 
	return min1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;

	
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1[i]=1;
	}
	sort(a,a+n);
	int flag=0,t=0;
	t=min();
	a[t]++;
	m--;
	sum++;
	while(m>=1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]==a[j]&&a1[j]==1){
					a[i]+=1;
					a1[j]=0;		
					sum++,m--;
					flag=1;
					break;	
				}
				else flag=0;
			}
			if(flag=0){
				t=min();
				a[t]++;
			}		
		}	
			
	}
	cout<<sum-3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
