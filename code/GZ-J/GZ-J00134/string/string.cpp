//GZ-J00134 南白初级中学  唐清倾 
#include <bits/stdc++.h>
using namespace std;
int n;//2*10^5
long long sum=0;
int a[200001]={};//10^9
char b[200001]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){//2*10^5
		cin>>a[i]>>b[i];
	}
	int i=1,j=n;
	while(i<j){//2*10^5
		if(b[i]!=b[j]){
			if(a[i]==a[j]){
				sum+=a[i];
				i++;
				j--;
			}
			else{
				int t;
				if(a[i]<a[j]){
					sum+=a[i];
					a[j]=a[j]-a[i];
					i++;
				}
				else{
					sum+=a[j];
					a[i]=a[i]-a[j];
					j--;
				}
			}
		}
		else{
			if(a[i]==a[j]){
				i++;
				j--;
			}
			else {
				if(a[i]<a[j]){
					a[j]=a[j]-a[i];
					i++;
				}
				else{
					a[i]=a[i]-a[j];
					j--;
				}
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
}

