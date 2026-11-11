#include<bits/stdc++.h>
//#define fin cin
//#define fout cout
#define ll long long
using namespace std;
vector<int> p,q;
int n,m,k;
int main(){
   ifstream fin;
   ofstream fout;
   fin.open("and.in");
   fout.open("and.out");
    fin>>n>>k;p=q={};
    for(int i=0;i<n;i++){
        fin>>m;
        p.push_back(m);
    }
    for(int i=29;i>=0;i--){
        for(int j:p){
            if(j&(1<<i)) q.push_back(j);
        }if(q.size()>=k) p=q;
        q={};
    }for(int i=0;i<k;i++){
        p[0]&=p[i];
    }fout<<p[0];
   fin.close();
   fout.close();
    return 0;
}
