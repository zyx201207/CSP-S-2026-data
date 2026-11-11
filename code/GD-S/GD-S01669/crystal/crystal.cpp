#include<bits/stdc++.h>
using namespace std;
int n,m,s;
vector<int> q;
vector<int> cha;
struct cry{
	int crystal;
	int fucrystal;
}c[100000];

int zc(){
	for(int i=1;i<n;i++){
		cha.push_back(q[i]-q[i-1]);
	}
	int more=0;
	for(int i=1;i<cha.size();i++){
		if(cha[more]<cha[i]){
			more=i;
		}
	}
	return more;
}

int jia(int be){
	int jsq,num=0,i=be-1;
	if(be>0){
		jsq=c[q[be]].crystal;
	}
	else{
		jsq=c[-q[be]].fucrystal;
	}
	while(m>0){
		if(q[i]<0){
			num+=cha[i];
			m-=num*c[-q[i]].fucrystal;
			jsq+=c[-q[i]].fucrystal;
		}
		else{
			num+=cha[i];
			m-=num*c[q[i]].crystal;
			jsq+=c[q[i]].crystal;
		}
		i--;	
	}
	i++;
	if(q[i]<0){
		return jsq-c[-q[i]].fucrystal-1;
	}
	else{
		return jsq-c[q[i]].crystal+1;
	}
	
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> s;
		q.push_back(s);
		if(s>=0){
			c[s].crystal++;
		}
		else{
			s*=(-1);
			c[s].fucrystal++;
		}
	}
	cout << jia(zc());
	return 0;
}
