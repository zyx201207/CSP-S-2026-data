#include<bits/stdc++.h>
using namespace std;
char ch[200005];
long long a[200005],n,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
	}
	for(int i=1,j=n;i<j;){
		if(a[i]==a[j]){
			if(ch[i]==ch[j]){
				i++;j--;
			}else{
				sum+=a[j];
				i++;j--;
			}
		}
		else{
			if(a[i]>a[j]){
				while(i<j){
				if(ch[i]==ch[j]){
					if(a[i]<=a[j]){
						a[j]-=a[i];
						break;
					}else{
						a[i]-=a[j];
						j--;
					}
				}else{
					if(a[i]<=a[j]){
					a[j]-=a[i];
					sum+=a[i];
					break;
					}else{
						a[i]-=a[j];
						sum+=a[j];
						j--;
					}
				}
			}
			i++;
			}else{
				while(i<j){
				if(ch[i]==ch[j]){
					if(a[j]<=a[i]){
						a[i]-=a[j];
						break;
					}else{
						a[j]-=a[i];
						i++;
					}
				}else{
					if(a[j]<=a[i]){
					a[i]-=a[j];
					sum+=a[j];
					break;
					}else{
						a[j]-=a[i];
						sum+=a[i];
						i++;
					}
				}
			}
			j--;
			}
		}
	}
	cout<<sum;
	return 0;
}
