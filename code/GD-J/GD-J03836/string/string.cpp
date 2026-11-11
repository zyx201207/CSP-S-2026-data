#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
	}
	int low=1,high=n;
	long long ans=0;
	while(low<high){
		if(a[low]<a[high]){
			if(c[low]!=c[high]){
				ans+=a[low];
			}
			a[high]-=a[low];
			low++;
		}else if(a[high]<a[low]){
			if(c[low]!=c[high]){
				ans+=a[high];
			}
			a[low]-=a[high];
			high--;
		}else{
			if(c[low]!=c[high]){
				ans+=a[high];
			}
			low++;
			high--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
