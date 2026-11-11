#include <fstream> 
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
struct strs{
	long long siz;
	char ltr;
};
int main(){
	vector<strs> h,r;
	queue<strs> l;
	ifstream fin("string.in");
	ofstream fout("string.out");
	char ci;
	bool lr=1;
	long long ai,n,cnt=0,pt=0;
	long long ans=0;
	fin >> n;
	fin >> ai >> ci;
	h.push_back((strs){ai,ci});
	cnt+=ai;
	n--;
	while(n--){
		fin >> ai >> ci;
		if(h.back().ltr==ci)h.back().siz+=ai;
		else h.push_back((strs){ai,ci});
		cnt+=ai;
	}
	pt=cnt/2;
	for(strs i:h){
		if(pt>=i.siz){
			lr=(pt>i.siz);
			pt-=i.siz;
			l.push(i);
		}
		else if(lr){
			l.push((strs){pt,i.ltr});
			i.siz-=pt+(cnt&1);
			r.push_back((strs){i.siz,i.ltr});
			lr=0;
		}
		else r.push_back(i);
	}
	long long u;
	while(!l.empty()){
		u=min(l.front().siz,r.back().siz);
		if(l.front().ltr==r.back().ltr){
			l.front().siz-=u;
			r.back().siz-=u;
			if(l.front().siz==0)l.pop();
			if(r.back().siz==0)r.pop_back();
		}
		else{
			ans+=u;
			l.front().siz-=u;
			r.back().siz-=u;
			if(l.front().siz==0)l.pop();
			if(r.back().siz==0)r.pop_back();
		}
	}
	fout << ans;
	fin.close();
	fout.close();
	return 0;
}
