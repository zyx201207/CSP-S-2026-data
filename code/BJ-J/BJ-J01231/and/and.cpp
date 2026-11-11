#include<bits/stdc++.h>
using namespace std;
int n,m;
int maxn=0;
int a[200200];
int main(){
	freopen("and.in","r"，stdin);
	freopen("and.out","w"，stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==2)
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if((a[i]&a[j])>maxn)maxn=a[i]&a[j];
		}
	}
	else if(m==3)
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			for(int z=0;z<j;z++){
				if((a[i]&a[j]&a[z])>maxn)maxn=a[i]&a[j]&a[z];
			}
		}
	}
	else if(m==4)
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			for(int z=0;z<j;z++){
				for(int endd=0;endd<z;endd++)
				if((a[i]&a[j]&a[z]&a[endd])>maxn)maxn=a[i]&a[j]&a[z]&a[endd];
			}
		}
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
