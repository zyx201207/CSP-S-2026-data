#include<bits/stdc++.h>
using namespace std;
#define int long long
struct seq{
    char c='\0';
    int s=0,e=0,len=0;
};
vector<seq> v;
seq makeseq(char c,int s,int e,int len){
    seq node;
    node.c=c;
    node.s=s;
    node.e=e;
    node.len=len;
    return node;
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long cnt=0;
    char c;
    int a;
    string s="";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
    }
    //cout<<s<<endl;
    int len=s.size();
    for(int i=0;i<len/2;i++){
        if(s[i]!=s[len-i]){
            cnt++;
        }
        //cout<<cnt<<" ";
    }
    cout<<cnt;
    /*
    cout<<"request cin:\n";
    cin>>n;
    //n=3;
    seq node;
    v.push_back(node);
    char aic;
    int ailen,ais,aie;
    int len=0;
    for(int i=1;i<=n;i++){
        cout<<"request cin:\n";
        cin>>ailen>>aic;
        ais=v.back().e+1;
        aie=ais+len-1;
        seq node;
        node.c=aic;
        node.len=ailen;
        node.s=ais;
        node.e=aie;
        v.push_back(node);
        len+=ailen;
    }
    int midpos=len/2;
    for(int i=1;i<v.size();i++){
        if(v[i].s<=midpos&&v[i].e>=midpos){
            seq node=v[i];
            v.erase(v.begin()+i);
            v.insert(v.begin()+i,makeseq(node.c,node.s,i,i-node.s+1));
            v.insert(v.begin()+i+1,makeseq(node.c,i+1,node.e,node.e-i));
            break;
        }
    }
    for(int i=1,j=v.size()-1;i<j;){
        int lena=v[i].len;
        int lenb=v[j].len;
        seq node1=v[i],node2=v[j];
        if(lena<lenb){
            int pos=v[j].e-lena;
            seq node=v[j];
            v.erase(v.begin()+j);
            v.insert(v.begin()+j,makeseq(node2.c,node2.s,pos,pos-node2.s+1));
            v.insert(v.begin()+j+1,makeseq(node2.c,pos+1,node2.e,node2.e-pos));
            j++;

        }
        else if(lena>lenb){
            int pos=v[i].s+lenb;
            seq node=v[i];
            v.erase(v.begin()+i);
            v.insert(v.begin()+i,makeseq(node1.c,pos,node1.e,node1.e-pos+1));
            v.insert(v.begin()+i/-1,makeseq(node1.c,node1.s,pos-1,pos-1+node1.s+1));
            i--;
        }
        if(v[i].c!=v[j].c){
            cnt+=min(lena,lenb);
        }
    }
    */
    //cout<<cnt;
}
