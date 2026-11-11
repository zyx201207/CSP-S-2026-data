#include<bits/stdc++.h>
using namespace std;
long long a[500005],t[300005];
long long s[500005];
bool cmp(long long a,long long b) {
	return a<b;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		memset(s,0,sizeof(s));
		for(int j=i;j<=n;j++) s[j]=a[j];
		int size1=n;
		for(int j=i;j<=n;j++){//a
			bool found=false;
			int des=0;
			for(int k=1;k<=size1;k++){
				if(!found&&s[k]==a[j]){
					found=true;
					s[k]=0;
					des=k;
				}
				else if(found){
					s[k]=0;
				}
			}
			if(des!=0){
				s[des]=a[j];
				size1=des;
			}
			else{
				s[size1+1]=a[j];
				size1++;
			}
			
		}
		sort(s+1,s+size1+1);
		for(int j=1;j<=size1;j++){
			if(s[j]!=s[j-1]) t[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
