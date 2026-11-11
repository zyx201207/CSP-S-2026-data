#include<bits/stdc++.h>
using namespace std;
struct node{
	int val,next=-1;
};
int main(){
	ifstream fin("and.in");
	ofstream fout("and.out");
	int n,m;
	fin>>n>>m;
	node a[n];
	for(int i=0;i<n;++i){
		fin>>a[i].val; 
		if(i<n-1)
			a[i].next=i+1;
	}
	int mark=1<<30,max=0;
	int head=0;
	while(mark){
		int cnt=0;
		for(int i=head;i!=-1;i=a[i].next){
			cnt+=((a[i].val&mark)!=0);
		}
		if(cnt>=m){
			int pre=-1;
			for(int i=head;i!=-1;i=a[i].next){
				if((a[i].val&mark)==0){
					if(pre==-1)
						head=a[i].next;
					else
						a[pre].next=a[i].next;
				}
				pre=i;
			}
			max|=mark;
		}
		mark>>=1;
	}
	fout<<max;
	return 0;
}
