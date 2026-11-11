#include<bits/stdc++.h>
using namespace std;
int n;
long long s=0;
struct num{
	int c;
	char le;
};
num a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].c>>a[i].le;
	}
	for(int left=1,right=n;left<right;){
		if(a[left].le!=a[right].le){
			if(a[left].c>a[right].c){
				a[left].c-=a[right].c;
				s+=a[right].c;
				right--;
			}
			else if(a[left].c<a[right].c){
				a[right].c-=a[left].c;
				s+=a[left].c;
				left++;
				
			}
			else{
				s+=a[left].c;
				left++;
				right--;
			}
		}
		else if(a[left].c>a[right].c){
			a[left].c-=a[right].c;
			right--;
		}
		else if(a[left].c<a[right].c){
			a[right].c-=a[left].c;
			left++;
		}
		else{
			left++;
			right--;
		}
		//for(int j=1;j<=n;j++)cout<<a[j].c<<a[j].le<<" ";
		//cout<<s<<" "<<left<<right<<" "<<endl;
	}
	cout<<s;
	return 0;
}
