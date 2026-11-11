#include <iostream>
#include <vector>

using namespace std;

int nums, m;
vector<int> v;
int mx=0;

void search(int index, int step, int num){
    int nnum;
    if(step!=0)
        nnum = num & v.at(index);
    else
        nnum = num;

    if(step+1==m){ 
        mx=max(mx, nnum);
    }else{
        for(int i=index+1; i<nums; i++){
            search(i, step+1, nnum); 
        }
    }
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin>>nums>>m;
    for(int i=0; i<nums; i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    
    for(int i=0; i<nums; i++){
        int num = v.at(i);
        search(i, 0, num); 
    }

    cout<<mx<<endl;
    
    return 0;
}
