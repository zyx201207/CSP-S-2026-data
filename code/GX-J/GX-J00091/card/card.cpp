#include<iostream>
#include<vector>
int bs[50005];
int resultbs[50005];
int arr[100005];
std::vector<int> desktop;
void getResult(){
    for(int k=0;k<desktop.size();k++){
        if(desktop[k]>0){
            resultbs[desktop[k]]++;
        }
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,t;
    std::cin>>n>>m,t;
    for(int i=0;i<n;i++){
        std::cin>>arr[i];//Input
        t=arr[i];
        if(bs[t]>0){
            desktop.clear();
            desktop.push_back(bs[i]);
            bs[t]=0;
        }
        bs[t]++;
        desktop.push_back(bs[i]);
    }
    getResult();

    for(int i=1;i<n;i++){
        for(int j=i;j<n;j++){
            int v=arr[j];
            if(bs[v]>0){
                desktop.clear();
                desktop.push_back(v);
                bs[v]=0;
            }
            bs[v]++;
            desktop.push_back(v);
        }
        getResult();

    }

    for(int i=1;i<=m;i++){//Out
        std::cout<<(((resultbs[i])>=n)?n \
                    :resultbs[i])<<" ";
    }
    return 0;
}
