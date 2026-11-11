#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Strings{
	int num;
	char ch;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,left,right;
	long long ans=0;
	cin>>n;
	left=1,right=n;
	for(int i=1;i<=n;i++)
		cin>>a[i].num>>a[i].ch;
	while(left<right){
		int leftn=a[left].num,rightn=a[right].num;
		char leftc=a[left].ch,rightc=a[right].ch;
		if(leftc==rightc){
			if(leftn<rightn){
				left++;
				a[right].num-=leftn;
			}
			else if(leftn>rightn){
				right--;
				a[left].num-=rightn;
			}
			else{
				left++;
				right--;
			}
		}
		else{
			if(leftn<rightn){
				left++;
				a[right].num-=leftn;
				ans+=leftn;
			}
			else if(leftn>rightn){
				right--;
				a[left].num-=rightn;
				ans+=rightn;
			}
			else{
				left++;
				right--;
				ans+=leftn;
			}
		}
	}
	cout<<ans;
	return 0;
}
