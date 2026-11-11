#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long n;
struct Node{
	long long a;
	char c;
}nodes[N];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>nodes[i].a>>nodes[i].c;
	}
	long long left=1,right=n;
	while(left<right){
		if(nodes[left].c==nodes[right].c){
			if(nodes[left].a==nodes[right].a){
				left++;
				right--;
			}else if(nodes[left].a<nodes[right].a){
				nodes[right].a-=nodes[left].a;
				left++;
			}else{
				nodes[left].a-=nodes[right].a;
				right--;
			}
		}else{
			if(nodes[left].a==nodes[right].a){
				ans+=nodes[left].a;
				left++;
				right--;
			}else if(nodes[left].a<nodes[right].a){
				ans+=nodes[left].a;
				nodes[right].a-=nodes[left].a;
				left++;
			}else{
				ans+=nodes[right].a;
				nodes[left].a-=nodes[right].a;
				right--;
			}
		}
	}
	cout<<ans;
	return 0;
} 
