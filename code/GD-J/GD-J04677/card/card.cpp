#include<bits/stdc++.h>
using namespace std;
int a[1000000],b[1000000];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	string s;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		s="";
		for(int j=i;j<n;j++){
			s+=a[j];
			for(int k=0;k<j;k++){
				if(s[k]==s[j]){
					for(int l=j;l>k;l--){
						s[l]-=s[l];
					}
				}
			}
		}
		for(int j=0;j<s.length;j++) b[int(s[j])]++;
		
	}
	for(int i=0;i<m;i++){
		cout << b[i] << " ";
	}
	return 0;
}
