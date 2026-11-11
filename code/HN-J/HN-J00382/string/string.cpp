#include<bits/stdc++.h>
using namespace std;
char c[200005];int a[200005];
int main(){
	long long sum=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;char words[26];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int x=0,y=n-1;x<y;){
		if(a[x]<a[y]){
			if(c[x]!=c[y]){
				sum+=a[x];
			}
			a[y]-=a[x];
			x++;
		}
		else if(a[x]>a[y]){
			if(c[x]!=c[y]){
				sum+=a[y];
			}
			a[x]-=a[y];
			y--;
		}
		else{
			if(c[x]!=c[y]){
				sum+=a[y];
			}
			x++,y--;
		}
	}
	cout<<sum;
	fclose(stdin);fclose(stdout);
	return 0;
}


