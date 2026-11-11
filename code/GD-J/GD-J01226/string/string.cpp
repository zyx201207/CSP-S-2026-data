#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a[200005],h,t,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char x;
		cin>>a[i];
		cin>>x;
		s[i]=x;
	}
	h=1;
	t=n;
	while(h<t){
		if(s[h]==s[t]){
			if(a[h]==a[t]){
				h++;
				t--;
			}
			else{
				if(a[h]>a[t]){
					a[h]=a[h]-a[t];
					t--;
				}
				else{
					a[t]=a[t]-a[h];
					h++;
				}
			}
		}
		else{
			if(a[h]==a[t]){
				sum+=a[h];
				h++;
				t--;
			}
			else{
				if(a[h]>a[t]){
					a[h]=a[h]-a[t];
					sum+=a[t];
					t--;
				}
				else{
					a[t]=a[t]-a[h];
					sum+=a[h];
					h++;
				}
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
