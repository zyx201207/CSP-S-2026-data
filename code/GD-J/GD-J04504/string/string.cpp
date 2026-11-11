#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
char b[200005];
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	int i=1,j=n;
	while(i<j){
		if(b[i]!=b[j]){
			int minn=min(a[i],a[j]);
			cnt+=minn;
			a[i]-=minn;
			a[j]-=minn;
			if(a[i]==0){
				i++;
			}
			if(a[j]==0){
				j--;
			}
		}else{
			int minn=min(a[i],a[j]);
			a[i]-=minn;
			a[j]-=minn;
			if(a[i]==0){
				i++;
			}
			if(a[j]==0){
				j--;
			}
		}
	}
	cout<<cnt<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
