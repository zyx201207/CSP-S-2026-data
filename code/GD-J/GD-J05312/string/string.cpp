#include<bits/stdc++.h>
long long n,a[200005],r;
char c[200005];
int main(){
	freopen("r","string.in",stdin);
	freopen("w","string.out",stdout);
	std::cin>>n;
	for(int i=1;i<=n;i++) std::cin>>a[i]>>c[i];
	for(int i=1,j=n;i<=j;){
		if(a[i]<a[j]){
			a[j]-=a[i];
			if(c[i]!=c[j]) r+=a[i];
			i++;
		}else if(a[i]>a[j]){
			a[i]-=a[j];
			if(c[i]!=c[j]) r+=a[j];
			j--;
		}else{
			if(c[i]!=c[j]) r+=a[i];
			i++;
			j--;
		}
	}
	std::cout<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
