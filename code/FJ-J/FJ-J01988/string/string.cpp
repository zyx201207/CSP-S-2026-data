#include<bits/stdc++.h> 
using namespace std;
long long b[100005],q1[100005]/*×ÖÄ¸*/,q2[100005]/*ÊýÁ¿*/,r,h=1,sum;
char a[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		r++;
		q1[r]=a[i]-96;
		q2[r]=b[i];
	}
	if(r==1) cout<<0;
	while(h<=r){
		if(q1[r]==q1[h]){
			if(q2[r]>q2[h]){
				q2[r]=q2[r]-q2[h];
				h++;
			}
			else if(q2[r]==q2[h]){
				h++;
				r--;
			}
			else{
				q2[h]=q2[h]-q2[r];
				r--;
			}
		}
		else{
			if(q2[r]>q2[h]){
				q2[r]=q2[r]-q2[h];
				sum+=q2[h];
				h++;
			}
			else if(q2[r]==q2[h]){
				sum+=q2[h];
				h++;
				r--;
			}
			else{
				q2[h]=q2[h]-q2[r];
				sum+=q2[r];
				r--;
			}
		}
	}
	cout<<sum;
	return 0;
}
