#include<bits/stdc++.h>
using namespace std;
struct number{
	long long nu;
	long long er;
};
number num[100005];
long long zer(long long a){
	long long an=0;
	int i=0;
	int yu[1000]={0};
	for(int p=0;p<=1000;p++){
		yu[p]=0;
	}
	while(a){
		
		if(a%2==1){
		    yu[i]=1;	
		}
		else{
			yu[i]=0;
		}
		a/=2;
		i++;
	}
	for(int j=i-1;j>=0;j--){
		long long df=1;
		for(int k=0;k<j;k++){
			df*=10;
		}
		
		an+=yu[j]*df;
		
	}
	return an;
}
bool cmp(number x,number y){

	return x.er>=y.er;
	
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    
    long long n,m;
    cin>>n>>m;
    
	for(long long i=1;i<=n;i++){
		cin>>num[i].nu;
		num[i].er=zer(num[i].nu);
	} 
	sort(num+1,num+1+n,cmp);
	long long ans=0;
	for(int i=2;i<=m;i++){
		ans=num[i].nu&num[i-1].nu;
		
	}
	cout<<ans;
	return 0;
}
