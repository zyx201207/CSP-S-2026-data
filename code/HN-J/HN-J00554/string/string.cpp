#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b[10000],sum=0;
	char c[10000];
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
cin>>a;
for(int i=1;i<=a;i++){
	cin>>b[i]>>c[i];
}
for(int i=1;i<=a;i++){
	if(c[i]!=c[a]){
		sum+=min(b[i],b[a]);
		if(b[i]>b[a]){
			b[i]-=b[a];
			i--;
			a--;
		}else{
			if(b[a]>b[i]){
				b[a]-=b[i];
			}else{
				a--;
			}
		}
	}
}
cout<<sum;
fclose(stdin);
fclose(stdout);
	return 0;
}
