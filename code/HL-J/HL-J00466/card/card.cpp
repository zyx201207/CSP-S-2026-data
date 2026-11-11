#include <bits/stdc++.h>
using namespace std;
string s,t;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ch=0;
	cin>>n>>m;
	int a[n],b[m],c[m+1];
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=m;i++){
		c[i]=0;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<=i;j++){
			if (s.size()>0){
				for (int k=0;k<s.size();k++){
					if(a[j]==int(s[k])){
						for (int o=0;o<=k;o++){
							t+=s[o];
						}
						ch=1;
						s=t;
						t.empty();
					}
				}
				if (ch==0){
					s+=a[j];
				}
				else{
					ch=0;
				}
			}
			else{
				s+=a[j];
			}
		}
		for (int j=0;j<s.size();j++){
			for (int k=1;k<=m;k++){
				if (int (s[i])==k){
					c[i]++;
				}
			}
		}
	}
	for (int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
