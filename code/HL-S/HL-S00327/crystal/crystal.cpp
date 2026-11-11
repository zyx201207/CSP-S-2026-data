 #include <bits/stdc++.h>
 using namespace std;
 long long a[500001];
 int main(){
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
 	long long n=0,m=0,i,j=-1,ans=0;
 	scanf("%lld %lld",&n,&m);
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for (i=0;i<n-2;i++){
		if ((a[i+2]-a[i+1])!=(a[i+1]-a[i])) break;
	}
	if (i==(n-3)){
		long long distance=a[i]-a[i-1];
		for (i=1;;i++){
			distance-=i*distance;
			if (distance<0) break;
		}
		printf("%lld",i);
		return 0;
	}
	
	for(i=0;i<n;i++){
		long long have=m,spend=0;
		for(j=1;j<i+1;j++){
			have-=a[i]-a[i-j];
			spend+=a[i]-a[i-j];
			if (have<0){
				break;
			}
		}
		
		if (j>ans){
			ans=j;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
