#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,a[200001],sum,jg;
char b[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	sum=sum/2;
	while(sum>0){
		int i=0;
		int j=n-1;
		if(b[j]!=b[i]){
			if(a[i]<a[j]){
				a[j]-=a[i];
				jg+=a[i];
				sum-=a[i];
				i++;
			}
			else if(a[i]>a[j]){
				a[i]-=a[j];
				jg+=a[j];
				sum-=a[j];
				j--;
			}
			else{
				jg+=a[j];
				sum-=a[j];
				j--;
				i++;
			}
		}
		else{
			if(a[i]<a[j]){
				a[j]-=a[i];
				sum-=a[i];
				i++;
			}
			else if(a[i]>a[j]){
				a[i]-=a[j];
				sum-=a[j];
				j--;
			}
			else{
				sum-=a[j];
				j--;
				i++;
			}
		}
	
	}
	cout<<jg<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

