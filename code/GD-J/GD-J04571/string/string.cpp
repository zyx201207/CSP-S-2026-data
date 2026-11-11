#include <bits/stdc++.h>
using namespace std;
struct node{
	int num;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,i;
	long long sum=0;
	cin>>n;
	deque<node> v(n);
	for(i=0;i<n;i++){
		cin>>v[i].num>>v[i].c;
	} 
	if(n==1){
		cout<<0;
		return 0;
	}
	while(v.size()){
		int li=0,ri=v.size()-1;
		if(v[li].num>v[ri].num){
			if(v[li].c!=v[ri].c){
				sum+=v[ri].num;
				v[li].num-=v[ri].num;
				v.pop_back();				
			}else{
				v[li].num-=v[ri].num;
				v.pop_back();
			}
		}else if(v[li].num<v[ri].num){
			if(v[li].c!=v[ri].c){
				sum+=v[li].num;
				v[ri].num-=v[li].num;
				v.pop_front();
			}else{
				v[ri].num-=v[li].num;
				v.pop_front();
			}
		}else{
			if(v[li].c!=v[ri].c){
				sum+=v[li].num;
				if(v.size()>1){
					v.pop_back();
					v.pop_front();
				}else break;				
			}else{
				if(v.size()>1){
					v.pop_back();
					v.pop_front();
				}else break;
			}
		}
	}
	cout<<sum;
	return 0;
}
