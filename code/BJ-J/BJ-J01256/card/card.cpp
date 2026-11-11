#include<iostream>
#include<vector>
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    std::cin>>n>>m;
    std::vector<int> cards;
    std::vector<int> success;
    success.resize(m, 0);
    for (int i=0;i<n;i++){
        int x;
        std::cin>>x;
        cards.push_back(x);
    }
    for (int i=0;i<n;i++){
        std::vector<int> o = {};
        for (int j=i;j<n;j++){
            o.push_back(cards[j]);
            for (int k=0;k<o.size()-1;k++){
                if (o[k] == cards[j]){/*
                    o.pop_back();
                    for (int l=0; l<o.size()-k; l++){
                        o.pop_back();
                    }*/
                    o.resize(k);
                    break;
                }
            }
            std::cout<<cards[j]<<std::endl;
            for (int k=0;k<o.size();k++){
                std::cout<<" "<<o[k];
            }
            std::cout<<std::endl<<"  "<<o.size()<<std::endl;
        }
        for (int j=0;j<o.size();j++){
            success[o[j]-1]++;
        }
    }

    for (int i=0;i<m;i++){
        std::cout<<success[i]<<" ";
    }
    return 0;
}

