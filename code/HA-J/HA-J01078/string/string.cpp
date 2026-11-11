#include<bits/stdc++.h>
using namespace std;
long long n,m[999999],k=0;
char mm[999999];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int ii=1;ii<=n;ii++){
		cin>>m[ii]>>mm[ii];
	}
	int i=1,j=n;
	while(i<j){
		if(mm[i]==mm[j]){
			if(m[i]>m[j]){
				m[i]=m[i]-m[j];
				j--;
			}else if(m[i]<m[j]){
				m[j]=m[j]-m[i];
				i++;
			}else if(m[i]==m[j]){
				i++;j--;
			}
		}else{
			if(m[i]>m[j]){
				m[i]=m[i]-m[j];
				k+=m[j];
				j--;
			}else if(m[i]<m[j]){
				m[j]=m[j]-m[i];
				k+=m[i];
				i++;
			}else if(m[i]==m[j]){
				k+=m[i];
				i++;j--;
			}
		}
	}
	cout<<k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
