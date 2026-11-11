#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],s=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<=n,j>=1;){
		if(j<i){
			break;
		}
		if(c[i]==c[j]){
			if(a[i]==a[j]){
				i++;
				j--;
				continue;
			}
			else if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
				continue;
			}
			else{
				a[j]-=a[i];
				i++;
				continue;
			}
		}
		else{
			if(a[i]==a[j]){
				s+=a[i];
				i++;
				j--;
				continue;
			}
			else if(a[i]>a[j]){
				s+=a[j];
				a[i]-=a[j];
				j--;
				continue;
			}
			else{
				s+=a[i];
				a[j]-=a[i];
				i++;
				continue;
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
