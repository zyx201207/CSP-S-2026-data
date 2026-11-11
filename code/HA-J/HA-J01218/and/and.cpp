#include<bits/stdc++.h>
using namespace std;
long long an(int a,int b){
	int a1[22],b1[22];
	long long ab=0;
	int i=0,j=0;
	while(a>0){
		a1[i]=a%2;
		i++;
		a/=2;
	}
	while(b>0){
		b1[j]=b%2;
		j++;
		b/=2;
	}
	for(int ii=0;ii<=max(i,j);ii++){
		if(a1[ii]==1 and b1[ii]==1){
			if(ii==0){
				ab+=1;
			}
			else{
				ab+=pow(2,ii);
			}
		}
		
	
}
return ab;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	
	if(b==1){
		int x,m=-1;
		for(int i=1;i<=a;i++){
			cin>>x;
			m=max(x,m);
		}
		cout<<m;
		return 0;
	}
	int aa[200005];
	if(b==2){
		for(int i=1;i<=a;i++){
			cin>>aa[i];
		}
		long long mm=-1;
		for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				mm=max(mm,an(aa[i],aa[j]));
			}
		}
		cout<<mm;
		return 0;
	}
	if(a==b){
		cout<<0;
		return 0;
	}
	else{
		for(int i=1;i<=a;i++){
			cin>>aa[i];
		}
		long long mm=-1;
		for(int i=1;i<=a;i++){
			for(int j=i+1;j<=a;j++){
				mm=max(mm,an(aa[i],aa[j]));
			}
		}
		cout<<mm;
		return 0;
	}
	
}