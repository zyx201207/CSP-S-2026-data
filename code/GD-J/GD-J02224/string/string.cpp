#include<bits/stdc++.h>
using namespace std;
struct st{
	long long a;
	char c;
}ar[200005] = {};
long long n,s = 0,ans = 0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ar[i].a>>ar[i].c;
		s+= ar[i].a;
	}
	int left = 1,right = n,lpos = 1,rpos = ar[n].a;
	while(left<right||(left==right&&lpos<rpos)){
		int leftn = ar[left].a - lpos + 1;
		if(ar[left].c!=ar[right].c){
			if(leftn < rpos){
				ans += leftn;
				rpos -= leftn;
				left++;
				lpos = 1;
			}else if(leftn > rpos){
				ans += rpos;
				lpos += rpos;
				right--;
				rpos = ar[right].a;
			}else{
				ans += rpos;
				left++;
				right--;
				rpos = ar[right].a;
				lpos = 1;
			}
		}else{
			if(leftn < rpos){
				rpos -= leftn;
				left++;
				lpos = 1;
			}else if(leftn > rpos){
				lpos += rpos;
				right--;
				rpos = ar[right].a;
			}else{
				left++;
				right--;
				rpos = ar[right].a;
				lpos = 1;
			}
		}
	}
	cout<<ans;
	return 0;
}

