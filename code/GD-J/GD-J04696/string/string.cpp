#include<bits/stdc++.h>
using namespace std;
int n,la,ii;
long long cs,a[200000];
char ls,s[200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>la>>ls;
		if(i>0){
			if(ls==s[ii]){
				a[ii]+=la;
			}
			else{
				ii++,a[ii]=la,s[ii]=ls;
			}
		}
		else{
			a[ii]=la,s[ii]=ls;
		}
	}
	for(int i=0,j=ii;i<=j;){
		if(s[i]!=s[j]){
			cs=cs+min(a[i],a[j]);
			if(a[i]>a[j]){
				a[i]-=a[j],j--;
			}
			else if(a[i]<a[j]){
				a[j]-=a[i],i++;
			}
			else{
				i++,j--;
			}
		}
		else{
			if(a[i]>a[j]){
				a[i]-=a[j],j--;
			}
			else if(a[i]<a[j]){
				a[j]-=a[i],i++;
			}
			else{
				i++,j--;
			}
		}
	}
	cout<<cs;
	return 0;
} 
