#include<bits/stdc++.h>
using namespace std;


struct Num{
	int a;
	int b;
	string c;
};

bool cmp(Num x,Num y){
	if(x.b!=y.b) return x.b>y.b;
	return x.a>y.a;
}

int n,m,ans;
Num num[200005];
//int dp[200005];


int max_num(int s){
	int max_a=0,tmpans=0,tmpa=0,tmpcnt=0;
	vector<int> ans1;
	tmpans=ans;
	while(tmpans){
		
		if(tmpans&1){
			ans1.push_back(tmpcnt);
		}
		tmpcnt+=1;
		tmpans>>=1;
	}
	for(int i=s;i<n;i++){
		if(num[i].b<ans1.size()){
			continue;
		}
		tmpa=0;
		for(int j=0;j<ans1.size();j++){
			if(num[i].c[ans1[j]]=='1'){
				tmpa+=0;
			}
		}
		if(tmpa>=ans1.size()){
			return num[i].a;
		}
		max_a=num[i].a;
	}
	return max_a;	
}


int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>num[i].a;
		int tmp=num[i].a;
		while(tmp){
			num[i].b+=tmp&1;
			num[i].c+=char(int(tmp&1)+'0');
			tmp=tmp>>1;
			
		}
		//cout<<"debug  "<<num[i].c<<endl;
	}
	sort(num,num+n,cmp);
	ans=num[0].a;
	for(int i=i;i<m;i++){
		//sort(num,num+n,cmp);
		ans&=max_num(i);
	}
	cout<<ans;
	
	return 0;
}
