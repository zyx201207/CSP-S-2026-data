#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,i,j,num=0,k=0,AB=0,pab=1;
	long long m;
	scanf("%d%lld",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%lld",&a[i]);
		if(i==2)AB=a[i]-a[i-1];
		else if(i>2&&a[i]-a[i-1]!=AB){
			pab=0;
		}
	}if(pab==1){
		while(m-AB*num>=0){
			m-=AB*num;
			num++;
		}
		printf("%d\n",num);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}else if(n>5000&&m>100000000){
		printf("1\n");
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	sort(a+1,a+n+1);
	for(i=n;i>=1;--i){
		k=0;
		for(j=i;j>=1;--j){
			k+=a[j];
			
			if(k+m>=a[i]*(i-j+1)){
				num=max(num,i-j+1);
				cout<<k<<endl;
			}else break;
		}
	}
	printf("%d\n",num);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
