#include<bits/stdc++.h>
using namespace std;
long long n,z[200050],x[200050],ans,m;
char y[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1,j=0;i<=n;i++){
		cin>>z[i]>>y[i];
		j+=z[i];
		x[i]=j;
	}
	m=x[n];
	for(long long i=1,j=n,k=1;k<=m/2;){
		if(i>=j)break;
		if(y[i]==y[j]){
			if(x[i]>m-x[j-1]){
				j--;
				k=m-x[j-1]+1;
			}else if(x[i]<m-x[j-1]){
				i++;
				k=x[i]+1;
			}else{
				i++;
				j--;
				k=x[i]+1;
			}
			continue;
		}
		if(x[i]>m-x[j-1]){
			ans+=m-x[j-1]-k+1;
			k=m-x[j-1]+1;
			j--;
		}
		if(x[i]<m-x[j-1]){
			ans+=x[i]-k+1;
			k=x[i]+1;
			i++;
		}
		if(x[i]==m-x[j-1]){
			ans+=x[i]-k+1;
			k=x[i]+1;
			i++;
			j--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
